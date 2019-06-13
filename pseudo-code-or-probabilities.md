INCLUSIVE "OR" FOR PROBABILITIES ALGORITHM  
    The most basic unit that we know of the inclusive "or" is P(A U B) = P(A) + P(B) - P(A)*P(B). In order to solve this in an  
  algorithm, Dynamic Programming (DP) can be used. The border cases are:  
      - P(0) = 0  
      - P(A) = a  
      - P(A U B) = a + b - a*b  
    Any other case would be like:  
      - P(A U ...) = a + ... - a*(...)  
    Where "..." is the function of more than 1 probabilities events (ie. B U C, B U C U D, etc.)  
    Having said that, we could define the DP like:  
    
```
function inclusiveOrProbability(Array probabilities):
    Int len = length(array)
    if (len === 0):
        return 0
    elseif (len === 1):
        return current(array)
    elseif (len === 2):
        Float first = current(array)
        Float second = next(array)
        return first + second - (first * second)
    else:
        Array rest = inclusiveOrProbability(array_slice(array, 1))
        Floatfirst = current(array)
        return first + rest - (first * rest)
```


ECVLUSIVE "OR" FOR PROBABILITIES ALGORITHM  
  This one is not hard at all, two events that not overlap so the reultant value of the sum is equal to the union of the probabilities.  
    -P(A U B) = P(A) + P(B)  
      
```
function exclusiveOrProbability(Array probabilities):  
    Int len = length(array)  
    if (len === 0):  
        return 0  
    else:  
        return array_sum(probabilities)  
```
