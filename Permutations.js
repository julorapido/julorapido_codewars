function permutations(string) {
    const res = [];
    for (let i = 0; i < (string.split('').length * string.split('').length + 400) ; i ++){
        let o = (string.split('')).sort((a, b) => 0.5 - Math.random());
        o = o.join('');
        if (!res.includes(o)){res.push(o)} 
    }
      return res;
  }