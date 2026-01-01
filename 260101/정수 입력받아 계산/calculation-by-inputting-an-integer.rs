use std::io;

fn main() {
    let mut input = String::new();

    io::stdin()
        .read_line(&mut input)
        .expect("읽기 실패");

    let a: i32 = input.trim().parse().expect("숫자가 아님");

    println!("{}", a * 2 + 3);
}