use ndarray::Array;
use ndarray_rand::RandomExt;
use ndarray_rand::rand_distr::Uniform;
use std::time::Instant;
use floating_duration::TimeAsFloat;
use std::thread;
use std::sync::Arc;

fn parallel_matrix_mul(a: Vec<Vec<f32>>, b: Vec<Vec<f32>>, num_threads: usize) -> Vec<Vec<f32>> {
    let rows = a.len();
    let cols = b[0].len();
    let common_dim = b.len();
    let b = Arc::new(b);
    let mut handles = Vec::new();
    let mut result = vec![vec![0.0; cols]; rows];

    let chunk_size = (rows + num_threads - 1) / num_threads;
    for chunk_start in (0..rows).step_by(chunk_size) {
        let chunk_end = (chunk_start + chunk_size).min(rows);
        let a_chunk = a[chunk_start..chunk_end].to_vec();
        let b = Arc::clone(&b);

        handles.push(thread::spawn(move || {
            let mut sub_result = vec![vec![0.0; cols]; a_chunk.len()];
            for i in 0..a_chunk.len() {
                for j in 0..cols {
                    for k in 0..common_dim {
                        sub_result[i][j] += a_chunk[i][k] * b[k][j];
                    }
                }
            }
            (chunk_start, sub_result)
        }));
    }

    for handle in handles {
        let (start, sub_result) = handle.join().unwrap();
        result[start..start + sub_result.len()].copy_from_slice(&sub_result);
    }

    result
}

/// Task 2: Multiply 2 matrices
pub fn task_2(n: u32, threads: u32) -> f64 {
    let a = Array::random((n as usize, n as usize), Uniform::new(-1.0, 1.0));
    let b = Array::random((n as usize, n as usize), Uniform::new(-1.0, 1.0));
    let now = Instant::now();
    {
        parallel_matrix_mul(a, b, threads);
    }
    now.elapsed().as_fractional_secs()
}
