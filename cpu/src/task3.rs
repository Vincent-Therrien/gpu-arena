use ndarray::Array;
use ndarray_rand::RandomExt;
use ndarray_rand::rand_distr::Uniform;
use std::time::Instant;
use floating_duration::TimeAsFloat;

// /// Task 3: Softmax function.
// pub fn task_3(n: u32, threads: u32) -> f64 {
//     let data = Array::random((n as usize, ), Uniform::new(-10.0, 10.0));
//     let now = Instant::now();
//     {
//         //
//     }
//     now.elapsed().as_fractional_secs()
// }
