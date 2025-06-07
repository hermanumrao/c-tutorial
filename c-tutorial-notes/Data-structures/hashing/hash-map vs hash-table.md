## Intro:
HashMap and Hashtable store key and value pairs in a hash table. When using a Hashtable or HashMap, we specify an object that is used as a key and the value that you want to be linked to that key.

### HashMap vs HashTable 

|S. No.|HashMap|HashTable|
|---|---|---|
|1|No method is synchronized|Every method is synchronized|
|2|Multiple threads can operate simultaneously and hence HashMap's object is not thread-safe|At a time only one thread is allowed to operate the HashTable's object. Hence it is thread-safe|
|3|Threads are not required to wait and hence relatively performance is high|It increases the waiting time of the thread and hence performance is low|
|4|Null is allowed for both key and value|Null is not allowed for both key and value. Otherwise, we will get a null pointer exception|
|5|It is introduced in the 1.2 version|It is introduced in the 1.0 version|
|6|It is non-legacy|It is a legacy|