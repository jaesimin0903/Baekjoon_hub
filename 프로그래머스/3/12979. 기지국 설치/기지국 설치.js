function solution(n, stations, w) {
    var answer = 0;

    var size = 2*w + 1
    
    //첫 안테나
    stations.sort((a,b)=>a-b)
    console.log(stations)
    const cal=(start,end,s)=>{
        var s_size = end - start + 1
        if(s_size <= 0)
            return 0;
        if(s_size % s === 0)
            return Math.floor(s_size/s)
        else
            return Math.floor(s_size/s) + 1
    }
    
    answer += cal(0,Math.max(-1,stations[0]-w-2),size)
    
    for(var i = 1;i<stations.length;i++){
        answer+=cal(stations[i-1]+w,stations[i]-w-2,size)
    }
    
    answer += cal(stations[stations.length-1]+w, n-1,size)

    return answer;
}