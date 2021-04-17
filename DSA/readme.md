```c
if(isQuestionNotAttempted() || isQuestionAttemptedWrong())
    return "No Credits"
else if(isSubQuestionNotAttempted() || isSubQuestionAttemptedWrong())
    return "No Credits"
else if(isWriteAProgram() && (isSourceCodeNotIncluded() || isOnlyScreenshotsIncluded()))
    return "No Credits"
else
    return "Credits"
```