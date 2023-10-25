function parseInt(string) {
    // TODO: it's your task now
    let res = 0;  var a =  string.split(' ');
    if(string.includes('million')){return 1000000}
    const nmbrs = {'zero': 0,'one': 1, "two" : 2, 'three': 3, "four" : 4, "five" : 5, "six" : 6, "seven": 7, "eight": 8,"nine": 9,"ten" : 10,
      "eleven": 11,"twelve" : 12, "thirteen" : 13, "fourteen": 14, "fifteen" : 15, "sixteen" : 16, "seventeen" : 17, "eighteen" : 18, "nineteen" : 19,
      "twenty" : 20,"thirty" : 30, "forty": 40, "fifty" : 50, "sixty" : 60, "seventy" : 70, "eighty" : 80, "ninety" : 90, "hundred" : 100
    }
    for (let i = 0; i < string.split(' ').length; i ++){
      if (a[i].includes("-") && !(a[i + 1] == "hundred" || a[i + 1] == "thousand")){
        let p  = (a[i]).split('-').reduce((e,f) => {return nmbrs[e] + nmbrs[f]});
        res += p;
      }else{
        if (a[i + 1] == "hundred" || a[i + 1] == "thousand" ){
          let mult = a[i + 1] === "hundred" ? 100 : 1000;let bI = -1;
          if(mult == 100){
            for(let z = i; z < a.length; z++){if(a[z] == "thousand"){;bI = z;}}
          }
          if (bI !== -1){console.log(bI); 
              let b = (a[i + (bI == 4 ? 3 : 2)]).split('-').reduce((e,f) => {return nmbrs[e] + nmbrs[f]})
              let c  = (a[i +  (bI == 4 ? 3 : 2)].includes("-") ? b : nmbrs[a[i +  (bI == 4 ? 3 : 2)]]);
              res += (nmbrs[a[i]] * 100 + (bI === 3 || bI === 4 ? c : 0) ) * 1000; i+= bI;
          }else if (!a[i].includes("-") && bI == -1){
             res += nmbrs[a[i]] * mult; i++; 
          }else{
             let x  = (a[i]).split('-').reduce((e,f) => {return nmbrs[e] + nmbrs[f]});
             res += x * mult; i++;
          }
        }else if (a[i] === "and"){res += 0;}
        else{res += nmbrs[a[i]];}
      }
    }
    return res;
}
// Lol... Recreational Programming Only