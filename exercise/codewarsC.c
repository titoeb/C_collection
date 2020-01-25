int solution(int number) {
    int iter = 1;
    int multiples[number];
    int multiple = 0;
    while (iter < number){
      if (iter % 3 == 0 || iter % 5 == 0){
        multiples[multiple] = iter;
        ++multiple;
      }

      ++iter;
    }
    
    int result =0;
    
    for (iter = 0; iter <= multiple; ++iter){
      result = result + multiples[iter]; 
      printf("%d", multiples[iter]);
      printf("%d", iter);
    }
    printf("%d", result);
    return result;
}