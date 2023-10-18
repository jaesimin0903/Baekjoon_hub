function solution(sizes) {
    var answer = 0;
    //sort 2 matrix
    
    //max X > max Y 
    //if x < y -> x change y
    sizes.sort((a,b)=>b[0]-a[0])
    var x_arr = sizes
    var maxX = x_arr[0][0]
    
    sizes.sort((a,b)=>b[1]-a[1])
    var y_arr = sizes
    var maxY = y_arr[0][1]
    if(maxX > maxY){
        for(var i = 0;i<sizes.length;i++){
        if(sizes[i][0]<sizes[i][1]){
            var tmp = sizes[i][1]
            sizes[i][1] = sizes[i][0]
            sizes[i][0] = tmp
        }
    }
    sizes.sort((a,b)=>b[1]-a[1])
    answer = parseInt(maxX) * parseInt(sizes[0][1])
    }else{
        for(var i = 0;i<sizes.length;i++){
        if(sizes[i][0]>sizes[i][1]){
            var tmp = sizes[i][1]
            sizes[i][1] = sizes[i][0]
            sizes[i][0] = tmp
        }
    }
    sizes.sort((a,b)=>b[0]-a[0])
        answer = parseInt(maxY) * parseInt(sizes[0][0])
    }
   
    
    
    
    return answer;
}