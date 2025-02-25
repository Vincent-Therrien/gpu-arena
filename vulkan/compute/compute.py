import os
import numpy as np
import kp


def compile_source(source):
    open("tmp_kp_shader.comp", "w").write(source)
    os.system("glslangValidator -V tmp_kp_shader.comp -o tmp_kp_shader.comp.spv")
    return open("tmp_kp_shader.comp.spv", "rb").read()


def kompute(shader):
    # 1. Create Kompute Manager with default settings (device 0, first queue and no extensions)
    mgr = kp.Manager()

    # 2. Create and initialise Kompute Tensors through manager

    # Default tensor constructor simplifies creation of float values
    tensor_in_a = mgr.tensor([2, 2, 2])
    tensor_in_b = mgr.tensor([1, 2, 3])
    # Explicit type constructor supports uint32, int32, double, float and bool
    tensor_out_a = mgr.tensor_t(np.array([0, 0, 0], dtype=np.uint32))
    tensor_out_b = mgr.tensor_t(np.array([0, 0, 0], dtype=np.uint32))

    params = [tensor_in_a, tensor_in_b, tensor_out_a, tensor_out_b]

    # 3. Create algorithm based on shader (supports buffers & push/spec constants)
    workgroup = (3, 1, 1)
    spec_consts = [2]
    push_consts_a = [2]
    push_consts_b = [3]

    # See documentation shader section for compile_source
    spirv = compile_source(shader)

    algo = mgr.algorithm(params, spirv, workgroup, spec_consts, push_consts_a)

    # 4. Run operation synchronously using sequence
    (mgr.sequence()
        .record(kp.OpTensorSyncDevice(params))
        .record(kp.OpAlgoDispatch(algo)) # Binds default push consts provided
        .eval() # evaluates the two recorded ops
        .record(kp.OpAlgoDispatch(algo, push_consts_b)) # Overrides push consts
        .eval()) # evaluates only the last recorded op

    # 5. Sync results from the GPU asynchronously
    sq = mgr.sequence()
    sq.eval_async(kp.OpTensorSyncLocal(params))

    # ... Do other work asynchronously whilst GPU finishes

    sq.eval_await()

    # Prints the first output which is: { 4, 8, 12 }
    print(tensor_out_a.data())
    # Prints the first output which is: { 10, 10, 10 }
    print(tensor_out_b.data())


if __name__ == "__main__":

    # Define a raw string shader (or use the Kompute tools to compile to SPIRV / C++ header
    # files). This shader shows some of the main components including constants, buffers, etc
    shader = """
        #version 450

        layout (local_size_x = 1) in;

        // The input tensors bind index is relative to index in parameter passed
        layout(set = 0, binding = 0) buffer buf_in_a { float in_a[]; };
        layout(set = 0, binding = 1) buffer buf_in_b { float in_b[]; };
        layout(set = 0, binding = 2) buffer buf_out_a { uint out_a[]; };
        layout(set = 0, binding = 3) buffer buf_out_b { uint out_b[]; };

        // Kompute supports push constants updated on dispatch
        layout(push_constant) uniform PushConstants {
            float val;
        } push_const;

        // Kompute also supports spec constants on initialization
        layout(constant_id = 0) const float const_one = 0;

        void main() {
            uint index = gl_GlobalInvocationID.x;
            out_a[index] += uint( in_a[index] * in_b[index] );
            out_b[index] += uint( const_one * push_const.val );
        }
    """
    kompute(shader)
