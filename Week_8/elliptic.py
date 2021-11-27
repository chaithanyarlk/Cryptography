def modInverse(a,b):
    for i in range(1,b):
        if(((a%b)*(i%b))%b == 1):
            return i
    return -1
def pointAddition(xp,xq,yp,yq,p):
    s = (yp-yq)%p*modInverse(xp-xq,p)
    xr = (s**2 - (xp+xq))%p
    yr = (s*(xp-xr)-yp)%p
    return [xr,yr]
def pointAddition1(xp,xq,yp,yq,p):
    s = (yp-yq)%p*modInverse(xp-xq,p)
    xr = (s**2 - (xp+xq))
    yr = (s*(xp-xr)-yp)%p
    return [xr,yr]
def pointCalculator(xp,yp,k):
    arr = []
    arr.append(0)
    arr.append([xp,yp])
    for i in range(2,k+1):
        if i%2 == 1:
            xr,yr = pointAddition(arr[i-1][0],xp,arr[i-1][1],yp,p)
            arr.append([xr,yr])
        else:
            xr,yr = pointDoubling(arr[int(i/2)][0],arr[int(i/2)][1],a,b,p)
            arr.append([xr,yr])
    return [arr[k][0],arr[k][1]]
def satisfy(x,p,a,b):
    val = x**3 + a*(x) +b
    val = math.sqrt((val%p))
    temp = math.floor(val)
    if temp == val:
        return temp
    return -1
def mtoPm(m,K,p,a,b):
    j = 0
    while satisfy(m*K+j,p,a,b) == -1:
        j += 1
    Pm = satisfy(m*K+j,p,a,b)
    return [m*K+j,Pm]
a = 1
b = 1
p = 4177
xp = 0
yp = 1
K = 30
secret_key_A = 5
secret_key_B = 4
Pa = pointCalculator(xp,yp,secret_key_A)# Shared public key of A
Pb = pointCalculator(xp,yp,secret_key_B)# Shared public key of B
print("a which is coefficient of x in Equation of curve",a)
print("b Constant in Equation of curve",b)
print("p The modular limit",p)
print("P or B the base Point","[",xp,",",yp,"]")
print("K the common value which is available to publicly",K)
print("Pa public key of A",Pa)
print("Pb public key of B",Pb)
print("The things that will be available publicly are (",a,",",b,",",p,",","[",xp,",",yp,"]",",",K,",",Pa,",",Pb,",",")")
# A will choose some random k with which he will send the value
message = 2174
Pmpoint = mtoPm(message,K,p,a,b)
print("Pm calculated by A is ",Pmpoint)
k = random.randint(2,p-1)
kB = pointCalculator(xp,yp,k)
kPb = pointCalculator(Pb[0],Pb[1],k)
encrypted = pointAddition(Pmpoint[0],kPb[0],Pmpoint[1],kPb[1],p)
print("The message that will be sent is [kB,(Pm+kPb)] [",kB,encrypted,"]")
pkB = pointCalculator(kB[0],kB[1],secret_key_B)
pkB[1] = -pkB[1] + p # As in subtraction we need to inverse sign of the y co ordinates
decrypted = pointAddition(encrypted[0],pkB[0],encrypted[1],pkB[1],p)
print("This is the decrypted point",decrypted)