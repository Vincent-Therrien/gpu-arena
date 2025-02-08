use clap::Parser;
mod task1;
mod task2;
mod task3;

/// Execute a multi-core accelerated program.
#[derive(Parser)]
#[command(version, about, long_about = None, arg_required_else_help = false)]
struct Cli {
    /// Task to execute. One of `1`, `2`, or `3`.
    #[arg(long, required = false)]
    task: Option<u32>,

    /// Input dimension.
    #[arg(long, required = false)]
    n: Option<u32>,

    /// Number of iterations to compute the mean duration.
    #[arg(long, required = false)]
    iterations: Option<u32>,

    /// Number of threads.
    #[arg(long, required = false)]
    threads: Option<u32>,
}

/// Program entry point.
fn main() {
    let cli = Cli::parse();
    let task: u32 = match cli.task {
        Some(i) => i,
        None => 1,
    };
    let n: u32 = match cli.n {
        Some(i) => i,
        None => 1000,
    };
    let iterations: u32 = match cli.iterations {
        Some(i) => i,
        None => 1,
    };
    let threads: u32 = match cli.threads {
        Some(i) => i,
        None => 1,
    };
    let mut total_duration = 0.0;
    for _ in 0..iterations {
        let duration = match &task {
            1 => task1::task_1(n, threads),
            2 => task2::task_2(n, threads),
            3 => task3::task_3(n, threads),
            _ => panic!("Invalid task."),
        };
        total_duration += duration;
    }
    let average = total_duration / (iterations as f64);
    println!("Average duration (s): {}", average);
}
