struct VertexPayload {
    @builtin(position) position: vec4<f32>,
    @location(0) color: vec3<f32>,
};

@vertex
fn vertices(@builtin(vertex_index) i: u32) -> VertexPayload {

    var positions = array<vec2<f32>, 3>(
        vec2<f32>(-0.75, -0.75),
        vec2<f32>( 0.75, -0.75),
        vec2<f32>(  0.0,  0.75),
    );

    var colors = array<vec3<f32>, 3>(
        vec3<f32>(1.0, 0.0, 0.0),
        vec3<f32>(0.0, 1.0, 0.0),
        vec3<f32>(0.0, 0.0, 1.0),
    );

    var out: VertexPayload;
    out.position = vec4<f32>(positions[i], 0.0, 1.0);
    out.color = colors[i];
    return out;
}

@fragment
fn fragment(in: VertexPayload) -> @location(0) vec4<f32> {
    let levels: f32 = 10.0;
    let quantizedColor: vec3<f32> = floor(in.color * levels) / (levels - 1.0);
    return vec4<f32>(quantizedColor, 1.0);
}
