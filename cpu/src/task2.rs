use ndarray::Array;
use ndarray_rand::RandomExt;
use ndarray_rand::rand_distr::Uniform;
use std::time::Instant;
use floating_duration::TimeAsFloat;

// /// Task 2: Multiply 2 matrices
// pub fn task_2(n: u32, threads: u32) -> f64 {
//     let data = Array::random((n as usize, n as usize), Uniform::new(-1.0, 1.0));
//     let now = Instant::now();
//     {
//         //
//     }
//     now.elapsed().as_fractional_secs()
// }
