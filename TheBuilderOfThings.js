// learned lot of new things ++
// rly cool kata
class Thing {
  // TODO: Make the magic happen 
  constructor(v){
    this.name = v;
    // handler get methods
    // proxy to decompose props 
    this.is_a = new Proxy(this, {
      get: (target, n) => {
         console.log("assignation => is_a " + n);
         if (typeof n === 'symbol') {
            return target[n];
         }
         const is_name = `is_a_${n}`;
         const opposite_isnot_name = `is_not_a_${n}`;
         Reflect.defineProperty(target, is_name, { value: true }); // true
         Reflect.defineProperty(target, 
        opposite_isnot_name, { value: false }); // [isnot] false
         return target[n];
      }
    });
    this.is_not_a = new Proxy(this, {
       get: (target, p) => {
         console.log("assignation => is_not_a " + p);
         const isnot_name = `is_not_a_${p}`;
         const opposite_is_name = `is_a_${p}`;
         Reflect.defineProperty(target, isnot_name, { value: true });
         Reflect.defineProperty(target, opposite_is_name, { value: false });
         return target[p];
       }
    });
    this.having = this.has = (n) => new Proxy(this, {
      get: (target, h) => {
          let res;
          console.log("has => " + n + " "+ h);
          if(n > 1){
            const has_propsname = `has_{n}_{h}`;
            res = (new Array(n)
              .fill(h.substring(0, h.length - 1))
              .map(a => new Thing(a))
            );
            // define propreties on nested items
            res.each = (callback) => {
                let str = callback.toString();
                console.log(str);
                const arrowIndex = str.indexOf('=>');
                const leProp = str.substring(0, arrowIndex - 1);
                str = `${leProp} => ${leProp}.${str.substring(arrowIndex + 3)}`;
                res.forEach(eval(str));
            }
          }else{
            res = new Thing(h);
          }
          Reflect.defineProperty(target, h, { value: res });
          return target[h];
      }
    });
    this.and_the = this.being_the = this.is_the = new Proxy(this, {
       get: (target, name) => {
          // +1 proxy props decomposition
          return new Proxy(target, {
                get: (t, tempProx_) => {
                    Reflect.defineProperty(t, name, { value: tempProx_ });
                    return target;
                }
            });;
       }
    });
    this.can = new Proxy(this, {
       get: (target, x) => {
          console.log(x);
          const t_c = (one, two) => {
              let callback = two ? two : one;
              let cacheProp = two ? one : null;
              let str = callback.toString();
              // regex of type $ { "a word " }
              let interpolationRegex = /\${(\w+)}/g;
              let finalFunc = str;
              let match;
              while (match = interpolationRegex.exec(str)) {
                  const v = target[match[1]]; // [1] of regex exec method
                  if (v)
                    finalFunc = finalFunc.replace(match[0], v); // replace fetched ${prop}
              }
              console.log(callback.toString());
              console.log(finalFunc);
              finalFunc = (eval(finalFunc)); // execute code trought str a.k.a str => func
              if(cacheProp){
                 console.log("cache.");
                 // +1 proxy for cached responses
                 finalFunc = new Proxy(finalFunc, {
                    apply: (e_V, thisArg, argumentsList) => {
                        // push or init arr of cached results
                        let h = target[cacheProp] ? target[cacheProp] : new Array();
                        h.push(e_V.apply(thisArg, argumentsList));
                        Reflect.defineProperty(target, cacheProp, { value: h });
                        return target;
                    }
                   
                 })
              }
              Reflect.defineProperty(target, x, { value: finalFunc });
          }
          return t_c;
       }
    })
  }

}




