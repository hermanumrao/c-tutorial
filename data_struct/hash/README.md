# Tutorial to hashing function

hthere are 2 types of hashing function
    -> dependant hashing
    -> independant hashing

## the most popular distribution independant function are:
    -> Division method
        (Basically modudo function)
    -> Mid Square method
        (take the square of a key and then eleminate digits from both ends uptil the required number of digits is reached)
    -> Folding method
        (for example if we are reading a key and our table is indexed 00to99 then we take the key and Divide its digits into groups of 2, then we add these grps to get a 2 digit number of required index
        ex- 
        for key =2103-> 21+03 = 24 
        for key =7148-> 71+48 = 19 (only last 2 digits of ans is considered) 
        )


## methods for handling hash collision:
    -> Open addrssing:
        most popular functions used are:
        **Linear Probing**
            *(put the value in the nearest free space present after the original key)
            H(k)=(h+i)%m    ;  i=0,1,2,3,...m*        
        **Quadratic Probing**
            *H(k)=(h+i^2)*
        **Double hashing**
            *H(k)=h+i(H')   ; where H' is a new function*
