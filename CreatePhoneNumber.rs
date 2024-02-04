fn create_phone_number(numbers: &[u8]) -> String {
    let mut s : String = String::new();
    for mut x in 0..9{
        if x == 0 || x == 3 || x == 6{
           let s1 = String::from(if x == 0{"("}else{" "});
           let s2 = String::from(if x == 0{")"}else{"-"});
           let c : String = numbers[x..x + if x > 3{4}else{3}].into_iter()
                .map(|a| a.to_string())
                .collect::<String>()
                .to_string();
            
            x += if x > 3{4}else{ 2 };
            s = if x <= 5{ s + &s1 + &c + &s2}else{ s + &c};
        }
    }
    return s;
}


