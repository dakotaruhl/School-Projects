Dakota Ruhl (dmr122)

I was able to complete all 3 modules a had a good understanding of how the probability models were being 
created. However, when it was time to evaluate them, i could not understand how the eval_module.m was
going to take into account the three probabilty models from the three modules, it simply detects the 
percentage of skin probabilitys given a test image. I tried to insert my skin_detection modules (1, 2, and 3)
into this eval_module.m function but it did not work, the patches were out of bounds.
I admittidly could not understand this part of the project and was not able to complete it. I was able to
create two arrays for skin detection and non skin detection, but did not see how i could create this for 
all three modules and plot the histogram. 

From my own eye test, it appears as if Module 1 is more accurate than Module 2, and Module 3 is the most accurate. 
I created one additional function to simplify the code in the script, it simply computes the STD and Mean values 
if given a patch of an image. 