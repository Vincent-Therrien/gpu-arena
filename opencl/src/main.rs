use ocl::ProQue;

pub fn trivial() -> ocl::Result<()> {
    const TEST_KERNEL_SOURCE: &str = include_str!("./test_kernel.cl");
    let pro_que = ProQue::builder()
        .src(TEST_KERNEL_SOURCE)
        .dims(1 << 20)
        .build()?;

    let buffer = pro_que.create_buffer::<f32>()?;

    let mut vec_i = vec![0.0f32; buffer.len()];
    buffer.read(&mut vec_i).enq()?;
    println!("The value at index [{}] is '{}'.", 200007, vec_i[200007]);

    let kernel = pro_que
        .kernel_builder("add")
        .arg(&buffer)
        .arg(10.0f32)
        .build()?;

    unsafe {
        kernel.enq()?;
    }

    let mut vec = vec![0.0f32; buffer.len()];
    buffer.read(&mut vec).enq()?;

    println!("The value at index [{}] is now '{}'!", 200007, vec[200007]);
    Ok(())
}

fn main() {
    trivial();
}
