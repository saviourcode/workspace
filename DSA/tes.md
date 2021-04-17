```c
startAssignmentSubmissionAttempt()
{
    //Base case
    if(isSubmissionCorrect())
        return;

    //Recursive case
    else
        startAssignmentSubmissionAttempt()   
}
```