fn camel_case(str: &str) -> String {
    return str.split(" ")
        .map(|s| {
            if s.len() > 0 {
                return s[0..1].to_uppercase() + &s[1..]
            } else {
                return String::from("");
            }
        })
        .collect::<Vec<String>>()
        .join("");
}


