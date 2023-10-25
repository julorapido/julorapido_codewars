function undoRedo(object) {
    let u_O = "";let l_O = []; let s = []; let redoSaved = [];
      return {
          set: function(key, value) {
        if ( object.hasOwnProperty(key) ) {s.push([key, object[key] ], true);}
        else{s.push( [key, value ] , false);};
        object[key] = value; l_O.push("set");
        return object;
      },
          get: function(key) {return object[key]},
          del: function(key) {s.push( [key, object[key] ] , null);l_O.push("del"); delete object[key]; return object;},
          undo: function() {
          if (l_O == []){throw new Error('f');}
          else{
              let lst = (s.length == 2 ? s : s[s.length - 1]);
              let redoSaved = (s.length == 2 ? s[0] : s[s.length - 1][0]);
              console.log(s)
              if(l_O[l_O.length - 1] == "del"){
                  object[lst[0][0]]= lst[0][1];
              }else{
                if (lst[1] == false){delete object[lst[0][0]];}
                else{object[lst[0][0]]= lst[0][1];}
              }
              s = s.pop();
          }
      },
          redo: function() {
      }
      };
  }