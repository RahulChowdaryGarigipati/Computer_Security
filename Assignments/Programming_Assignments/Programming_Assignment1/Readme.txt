The program can be used by following the commands required to compile and run:

To Compile: Use the command "g++ main.cpp -o main".

To Run: Use the command ".\main".

Here we assign the plaintext letters to the positions in the ciphertext according to the frequency mapping of the english language and hence we map the letters as below,

The Decryption key is " if(ciphertext = k) then map the ciphertext to 'E'.
                        if(ciphertext = R) then map the ciphertext to 'T'.
                        if(ciphertext = B) then map the ciphertext to 'O'.
                        if(ciphertext = T) then map the ciphertext to 'I'.
                        if(ciphertext = P) then map the ciphertext to 'N'.
                        if(ciphertext = V) then map the ciphertext to 'S'.
                        if(ciphertext = I) then map the ciphertext to 'A'.
                        if(ciphertext = L) then map the ciphertext to 'H'.
                        if(ciphertext = W) then map the ciphertext to 'R'.
                        if(ciphertext = J) then map the ciphertext to 'C'.
                        if(ciphertext = C) then map the ciphertext to 'L'.
                        if(ciphertext = B) then map the ciphertext to 'O'.
                        if(ciphertext = A) then map the ciphertext to 'H'.
                        if(ciphertext = N) then map the ciphertext to 'U'.
                        if(ciphertext = O) then map the ciphertext to 'G'.
                        if(ciphertext = Y) then map the ciphertext to 'D'.
                        if(ciphertext = Q) then map the ciphertext to 'F'.
                        if(ciphertext = S) then map the ciphertext to 'Y'.
                        if(ciphertext = M) then map the ciphertext to 'W'.
                        if(ciphertext = E) then map the ciphertext to 'V'.
                        if(ciphertext = G) then map the ciphertext to 'K'.
                        if(ciphertext = Z) then map the ciphertext to 'P'.
                        if(ciphertext = U) then map the ciphertext to 'B' ".

We do manual shifting because the plaintext we want should be a meaningful plaintext.                        
Therefore, the letters for which a manual shift was done to give a meaningful plaintext are: "B, P, I, A, O, Q, Y, E, M, S, G, U, Z".

The plaintext produced is "EVENTHOUGHWEDONTKNOWWHICHCOHPANIESTHENSAHASCOHPROHISEDORBYWHATHEANSKNOWINGTHATTHEYCOULDHAVECOHPROHISEDANYOFTHEHISENOUGHTOHAKEUSHISTRUSTFULOFALLOFTHEHTHISISGOINGTOHAKEITHARDFORLARGECOHPANIESLIKEGOOGLEANDHICROSOFTTOGETBACKTHETRUSTTHEYLOSTEVENIFTHEYSUCCEEDINLIHITINGGOVERNHENTSURVEILLANCEEVENIFTHEYSUCCEEDINIHPROVINGTHEIROWNINTERNALSECURITYTHEBESTTHEYLLBEABLETOSAYISWEHAVESECUREDOURSELVESFROHTHENSAEDCEPTFORTHEPARTSTHATWEEITHERDONTKNOWABOUTORCANTTALKABOUT".