function doubles(maxk, maxn) {
    var g = 0; let p = {};
    for (let k = 1; k <= maxk; k++){
      for (let i = 1; i <= maxn; i++){
        let y = (1 / (k*  Math.pow(i + 1, 2 * k))  );
        if (g == g+y){;break;}
        g += y;
      }
    }
    return g;
  } 