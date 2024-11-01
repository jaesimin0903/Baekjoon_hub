const input = require('fs')
  .readFileSync(process.platform === "linux" ? "/dev/stdin" : "./input.txt", "utf-8")
  .replace(/\r/g, "")
  .trim()
  .split("\n")
  .map(String);

  
  const [m, n, l, k] = input[0].split(' ').map(Number);
  const stars = [];
  
  for (let i = 1; i <= k; i++) {
      const [r, c] = input[i].split(' ').map(Number);
      stars.push([r, c]);
  }
  
  let result = 0;
  
  for (let i = 0; i < stars.length; i++) {
      for (let j = 0; j < stars.length; j++) {
          let cnt = 0;
  
          for (let cur = 0; cur < stars.length; cur++) {
              const [curR, curC] = stars[cur];
  
              if (stars[i][0] <= curR && curR <= stars[i][0] + l &&
                  stars[j][1] <= curC && curC <= stars[j][1] + l) {
                  cnt += 1;
              }
          }
          
          result = Math.max(result, cnt);
      }
  }
  
  console.log(k - result);
  