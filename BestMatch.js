function bestMatch(ALAHLYGoals, zamalekGoals) {
  //coding and coding..
  const mp = new Map();
  let x = Number.MAX_VALUE;
  for(let i = 0; i < ALAHLYGoals.length; i ++){
    let s = ALAHLYGoals[i] - zamalekGoals[i];
    if(s < x){
      mp.set(s, [i, zamalekGoals[i] ]); 
      x = s;
    }
    else if(mp.get(s)){
      if( mp.get(s)[1] < zamalekGoals[i] ) mp.set(s, [i, zamalekGoals[i] ] );
    }
  }
  return mp.get(x)[0];
}


