#[allow(unused_macros)]
macro_rules! read {
    ($out:ident as $type:ty) => {
        let mut inner = String::new();
        std::io::stdin().read_line(&mut inner).expect("A String");
        let $out = inner.trim().parse::<$type>().expect("Parsable");
    };
}

#[allow(unused_macros)]
macro_rules! read_str {
    ($out:ident) => {
        let mut inner = String::new();
        std::io::stdin().read_line(&mut inner).expect("A String");
        let $out = inner.trim();
    };
}

#[allow(unused_macros)]
macro_rules! read_vec {
    ($out:ident as $type:ty) => {
        let mut inner = String::new();
        std::io::stdin().read_line(&mut inner).expect("A String");
        let $out = inner
            .trim()
            .split_whitespace()
            .map(|s| s.parse::<$type>().expect("Parsable"))
            .collect::<Vec<$type>>();
    };
}

fn main() {
    read!(_n as i64);
    read_vec!(v as usize);

    let mut probabilities = [0; 13];
    for i in 1..=6 {
        for j in 1..=6 {
            probabilities[i + j] += 1;
        }
    }

    println!("{}", v.into_iter().map(|x| probabilities.get(x).unwrap()).sum::<i32>() as f64 / 36.0);
}
