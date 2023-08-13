use std::io::stdin;
use std::iter::FromIterator;

fn main() {
    let mut workhorse = String::new();
    stdin().read_line(&mut workhorse).unwrap();
    let mut iter = workhorse.trim().split(" ").map(|s| s.parse::<usize>().unwrap());

    let t = iter.next().unwrap();
    let b = iter.next().unwrap();

    workhorse.clear();
    stdin().read_line(&mut workhorse).unwrap();

    let tis = Vec::from_iter(workhorse.trim().split(" ").map(|s| s.parse::<usize>().unwrap()));

    let mut packs = Vec::new();

    for _ in 0..t {
        workhorse.clear();
        stdin().read_line(&mut workhorse).unwrap();

        let mut iter = workhorse.trim().split(" ");
        
        let name = iter.next().unwrap().to_string();
        let v : u64 = iter.next().unwrap().parse().unwrap();

        packs.push((name, v));
    }


    let mut stores = Vec::new();
    for i in 0..b {
        let mut store = Vec::new();

        for _ in 0..tis[i] {
            workhorse.clear();
            stdin().read_line(&mut workhorse).unwrap();

            let mut iter = workhorse.trim().split(" ");
            
            let name = iter.next().unwrap().to_string();
            let v : u64 = iter.next().unwrap().parse().unwrap();

            store.push((name, v));
        }

        stores.push(store);
    }

    let mut diffs = Vec::new();
    for store in stores {
        let mut diff = 0;
        for (name, v) in store {
            diff += packs.iter().find(|x| x.0 == name).unwrap().1 - v;
        }
        diffs.push(diff);
    }

    for diff in diffs {
        println!("{}", diff);
    }
}

