BEGIN
INPUT A, B, C
  if A==B AND A==C then
    PRINT A, B, C
  end if
  
  if A>=B AND A>=C then
    if A==B OR A==C then
      if A==B then
        PRINT A, B
      else
        PRINT A, C
      end if  
    else
      PRINT A;
    end if  
  else
    if B>=C then
      if B==C then
        PRINT B, C
      else
        PRINT B
      end if  
    else
      PRINT C
  end if
END