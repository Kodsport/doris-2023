#![deny(nonstandard_style)]

#[allow(dead_code)]
fn getline() -> String {
    let mut res = String::new();
    std::io::stdin().read_line(&mut res).expect("a string");
    res.trim().to_string()
}

#[allow(unused_macros)]
macro_rules! read {
    ($out:ident as Vec<$type:ty>) => {
        let $out = getline()
            .split_whitespace()
            .map(|s| s.parse::<$type>().expect("parsable"))
            .collect::<Vec<$type>>();
    };
    ($out:ident as $type:ty) => {
        let $out = getline().trim().parse::<$type>().expect("parsable");
    };
    ($out1:ident, $out2:ident as $type1:ty, $type2:ty) => {
        let inner = getline();
        let mut iter = inner.trim().split_whitespace();
        let $out1 = iter
            .next()
            .expect("a token")
            .parse::<$type1>()
            .expect("parsable");
        let $out2 = iter
            .next()
            .expect("a token")
            .parse::<$type2>()
            .expect("parsable");
    };
    ($out1:ident, $out2:ident, $out3:ident as $type1:ty, $type2:ty, $type3:ty) => {
        let inner = getline();
        let mut iter = inner.trim().split_whitespace();
        let $out1 = iter
            .next()
            .expect("a token")
            .parse::<$type1>()
            .expect("parsable");
        let $out2 = iter
            .next()
            .expect("a token")
            .parse::<$type2>()
            .expect("parsable");
        let $out3 = iter
            .next()
            .expect("a token")
            .parse::<$type3>()
            .expect("parsable");
    };
}

fn main() {
    read!(_n as i64);
    println!(
        "{}",
        getline()
            .chars()
            .map(|chr| if '0' <= chr && chr <= '9' { chr } else { ' ' })
            .collect::<String>()
            .as_str()
            .split_whitespace()
            .map(|substr| substr.parse::<i64>().unwrap_or(0))
            .max()
            .unwrap()
    );
}
