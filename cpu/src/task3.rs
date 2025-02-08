use ndarray::Array;
use ndarray_rand::RandomExt;
use ndarray_rand::rand_distr::Uniform;
use std::time::Instant;
use floating_duration::TimeAsFloat;
use std::thread;
use std::sync::Arc;

fn parallel_softmax(numbers: Vec<f32>, num_threads: usize) -> f32 {
    let numbers = Arc::new(numbers);
    let chunk_size = (numbers.len() + num_threads - 1) / num_threads;
    let mut handles = Vec::new();

    for i in 0..num_threads {
        let numbers = Arc::clone(&numbers);
        handles.push(thread::spawn(move || {
            numbers.iter().skip(i * chunk_size).take(chunk_size).sum::<f32>()
        }));
    }

    handles.into_iter().map(|h| h.join().unwrap()).sum()
}

/// Task 3: Softmax function.
pub fn task_3(n: u32, threads: u32) -> f64 {
    let data = Array::random((n as usize, ), Uniform::new(-10.0, 10.0));
    let now = Instant::now();
    {
        parallel_softmax(data, threads);
    }
    now.elapsed().as_fractional_secs()
}
