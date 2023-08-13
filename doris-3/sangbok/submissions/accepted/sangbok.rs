use std::io::stdin;
use std::collections::BinaryHeap;

fn main() {
    let mut string = String::new();
    stdin().read_line(&mut string).unwrap();

    let mut iter = string.trim().split(" ").map(|x| x.parse::<u64>().unwrap());
    let s_max = iter.next().unwrap()*60;
    let _n = iter.next().unwrap();

    string.clear();
    stdin().read_line(&mut string).unwrap();

    let mut sum = 0;
    let mut queue = BinaryHeap::new();

    for s in string.trim().split(" ").map(|x| x.parse::<u64>().unwrap()) {
        queue.push(s);
        sum += s;

        if sum > s_max {
            sum -= queue.pop().unwrap();
        }
    }

    println!("{}", sum);
}
