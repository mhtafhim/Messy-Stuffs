INCLUDE 'EMU8086.INC'
.MODEL
.STACK 100H

.DATA
     CHAR DB ?
     
.CODE

    MAIN PROC
               
        MOV AX,@DATA
        MOV DS,AX   
               
               
         
               
            PRINT "ENTER THE UPPERCASE LETTER :   "
           
               
            MOV AH,1
            INT 21H
            MOV CHAR,AL
            
            ADD CHAR,32  
              
            
            
            MOV AH,2
            MOV DL,0AH     ; FOR\n
            INT 21H
            MOV DL,0DH     ; FOR \r
            INT 21H    
            
            PRINT "THE LOWER CASE IS:  "
              
              
            MOV AH,2
            MOV DL,CHAR
            INT 21H  
            
       
        
        
            MOV AH,4CH
            INT 21H
            
            MAIN ENDP
    
    END MAIN