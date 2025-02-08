use ndarray::Array;
use ndarray_rand::RandomExt;
use ndarray_rand::rand_distr::Uniform;
use std::time::Instant;
use floating_duration::TimeAsFloat;
use std::thread;
use std::sync::Arc;

fn parallel_sum(numbers: Vec<f64>, num_threads: usize) -> f64 {
    let numbers = Arc::new(numbers);
    let chunk_size = (numbers.len() + num_threads - 1) / num_threads;
    let mut handles = Vec::new();

    for i in 0..num_threads {
        let numbers = Arc::clone(&numbers);
        handles.push(thread::spawn(move || {
            numbers.iter().skip(i * chunk_size).take(chunk_size).sum::<f64>()
        }));
    }

    handles.into_iter().map(|h| h.join().unwrap()).sum()
}

/// Task 1: Compute the sum of elements in a 1D array.
pub fn task_1(n: u32, threads: u32) -> f64 {
    let data = Array::random((n as usize, ), Uniform::new(-1.0, 1.0)).to_vec();
    let now = Instant::now();
    {
        parallel_sum(data, threads as usize);
    }
    now.elapsed().as_fractional_secs()
}
