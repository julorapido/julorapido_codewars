function validateBattlefield(field : number[][]) {
    // write your magic here
      var ships = {"battleship": [4, 0, 1],"cruisers" : [3, 0, 2], "destroyers" : [2, 0, 3], "submarines" : [1, 0, 4] };
      for (let i = 0; i < field.length; i ++){
          for( let s = 0; s < field[i].length; s ++){
              if (field[i][s] == 1){
                let vertSens : any = null;let ShipLen = 0;let source = s;
                if(field[i + 1][s] == 1 || (i > 0 && field[i - 1][s] == 1) ) {vertSens = true;}
                else{vertSens = false;} //Horizontal
                if (vertSens === false){
                  for (let h = s; h < field[i].length; h ++){
                      if(field[i][h] === 0 || h == field[i].length){
                        s += h - s;
                        break;
                      }
                      ShipLen++;
                  }
                }             
                if (vertSens){
                  let notAlr = true;
                  if (i !== 0 && field[i - 1][s]){ notAlr = false;}
                  if(notAlr){
                    for (let v = i; v < field.length; v++){
                      if (field[v][s] === 0 || field[v][s] === null){break;}
                      ShipLen++;
                    }
                  }
                }
                if (ShipLen > 0){
                  const scanPoint = (xValue : number, yValue : number) => {
                      let crn0 = (xValue > 0 ? field[xValue -1][yValue -1 ] : 0); let crn1 = (xValue == field.length ? field[xValue + 1][yValue +1 ] : 0);
                      let crn2 = (yValue > 0 ? field[xValue + 1][yValue -1 ] : 0);let crn3 = (yValue == field[xValue][yValue].length ? field[xValue - 1][yValue +1 ] : 0);
                     // console.log("topL:" + crn0 + " topR:"  +crn1 + " botL:" + crn2 + " botR:" + crn3);
                      return crn0 + crn1 + crn2 + crn3;
                  }
                  let scanStr = scanPoint(i, source);
                  let scanEnd = scanPoint(i + (ShipLen - 1), source);
                  if (!vertSens){scanEnd = scanPoint(i, source + (ShipLen - 1));}
                  
                  if (scanStr === 1 || scanEnd === 1){return false;}
                  
                  for (const shp in ships){if(ships[shp][0] === ShipLen){ships[shp][1]++;}}
                }
              }
          }
      }
    let res = true;
    for (const shp in ships){
      if(ships[shp][1] !== ships[shp][2] ){res = false;}
    }
    return res 
    
  }
  //Bruh