function topThreeWords(text) {
    let res = {};
    text.split(' ').map(w =>{
      let aps = w.indexOf("'");
      if (w.length > 0){
          let wL = w.toLowerCase(); wL = wL.replace(/[^a-zA-Z]+/g, '');
          if(aps !== -1 && wL.length > 0){ wL = wL.slice(0, aps) + "'" + wL.slice(aps);}
          if(wL.length > 0){
            let o = res[wL]; res[wL] = isNaN(o) ? 1 : res[wL] + 1 ;
          }
      }
    });
    res = Object.entries(res).sort((a,b)=>b[1]-a[1]).map((el, index)=>el[0]);
    return res.splice(0, 3);
  }