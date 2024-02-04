   fn narcissistic(num: u64) -> bool {
    let num_as_string = num.to_string();
    let mut res : u64 = 0;
    for c in num_as_string.chars(){
        let a: u64 = (c.to_digit(10)).unwrap_or(0) as u64;
        let i =  u64::pow(
            a, num_as_string.len() as u32
        );
        res += i as u64;
    }
    if res == num { return true;}
    else{ return false;}
}


