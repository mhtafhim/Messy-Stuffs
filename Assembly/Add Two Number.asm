.MODEL
.STACK 100H

.DATA
     NUM1 DB ?
     ANS DB ?
     ALERT DB 'PLEASE ENTER 2 DIGIT WHOSE  SUM IS LESS THAN 10 $ '
     FIRST DB 'ENTER THE FIRST DIGIT : $  ' 
     SECOND DB 'ENTER THE SECOND DIGIT : $ '
     RESULT DB 'THE SUM IS = $'
     
.CODE

    MAIN PROC
               
        MOV AX,@DATA
        MOV DS,AX   
               
               
         
               
            MOV AH,9
            LEA DX,ALERT         ;LOAD EFFECTIVE ADDRESS
            INT 21H  
             
             
            MOV AH,2
            MOV DL,0AH           ; FOR\n
            INT 21H
            MOV DL,0DH           ; FOR \r
            INT 21H 
             
               
            MOV AH,9             ;PRINTING FIRST STRING
            LEA DX,FIRST     
            INT 21H
               
            
               
            MOV AH,1             ;TAKING FIRST USER INPUT
            INT 21H
            MOV NUM1,AL
            
            SUB NUM1,48          ;SUBTRACTING 48 FROM THE ASCII VALUE
              
            
            
            MOV AH,2
            MOV DL,0AH           ; FOR\n
            INT 21H        
            MOV DL,0DH           ; FOR \r
            INT 21H    
            
            
            MOV AH,9             ;PRINTING SECOND STRING
            LEA DX,SECOND
            INT 21H
            
            
              
            MOV AH,1             ;TAKING 2ND USER INPUT 
            INT 21H 
           
            ADD AL,NUM1          ;ADDING FIRST AND SECOND NUMBER
            MOV ANS,AL
           
              
            
            MOV AH,2
            MOV DL,0AH           ; FOR\n
            INT 21H
            MOV DL,0DH           ; FOR \r
            INT 21H    

                     
            
            MOV AH,9             ;PRINTING FINAL RESULT PROMPT 
            LEA DX,RESULT
            INT 21H         
           
                 
  
            MOV AH,2             ;PRINTING THE FINAL SUM OF TWO NUMBER
            MOV DL,ANS
            INT 21H   
            
       
        
        
            MOV AH,4CH
            INT 21H
            
            MAIN ENDP
    
    END MAIN