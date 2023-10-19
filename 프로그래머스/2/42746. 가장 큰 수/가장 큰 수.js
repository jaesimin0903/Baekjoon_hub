function solution(numbers) {
    var answer = '';
    var res = []
    
    numbers = numbers.map(
        v=>
     
            v.toString()
    )
    
    numbers.sort((a,b)=>(b+a)-(a+b))
    count=0;
    for(var i = 0;i<numbers.length;i++){
        if(numbers[i]==='0')
            count++;
        else
            break
    }
    if(count === numbers.length) return '0'
    return numbers.join('')
    
    //answer = (Math.max(...res)).toString()
    return answer;
}

function permutation(arr,size,res){
    if(size==1){
        res.push(arr.join(''))        
    }
    for(var i= 0;i<size;i++){
        permutation(arr,size-1,res)
        
        const swapIndex = size%2?0:i;
        [arr[swapIndex],arr[size-1]]=[arr[size-1],arr[swapIndex]]
    }
}