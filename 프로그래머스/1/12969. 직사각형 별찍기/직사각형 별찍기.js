process.stdin.setEncoding('utf8');
process.stdin.on('data', data => {
    const n = data.split(" ");
    const a = Number(n[0]), b = Number(n[1]);
    
    
    for(var j = 0;j<b;j++){
        var str= ""
        for(var i = 0;i<a;i++){
            str+="*"
        }
        console.log(str)
    }
});