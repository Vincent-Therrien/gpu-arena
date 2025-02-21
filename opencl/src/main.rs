/// Simple example with OpenCL. The function creates a vector and modifies its value on GPU.

use ocl::core;
use ocl::ProQue;

fn sum_reduce() -> ocl::Result<()> {
    const TEST_KERNEL_SOURCE: &str = include_str!("./test_kernel.cl");
    let pro_que = ProQue::builder()
        .src(TEST_KERNEL_SOURCE)
        .dims(1 << 20)
        .build()?;

    let buffer = pro_que.create_buffer::<f32>()?;
    let vec_i = vec![1.0; buffer.len()];
    let mut event = core::Event::null();
    println!("The value at index [{}] is initially '{}'.", 60, vec_i[60]);
    unsafe {
        let _ = core::enqueue_write_buffer(
            &pro_que,
            &buffer,
            false,
            0,
            &vec_i,
            None::<core::Event>,
            Some(&mut event),
        );
        let kernel = pro_que.kernel_builder("add").arg(&buffer).build()?;
        kernel.enq()?;
    }

    let mut vec = vec![0.0; buffer.len()];
    buffer.read(&mut vec).enq()?;
    println!("The value at index [{}] is now '{}'!", 60, vec[60]);
    Ok(())
}

fn list_devices() {

}

fn main() {
    let _ = sum_reduce();
}
