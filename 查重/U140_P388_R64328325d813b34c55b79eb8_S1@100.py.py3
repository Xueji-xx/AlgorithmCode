def two(a, b):    if a != 1:        two(a // 2, b + 1)        if a%2 == 1:            if b == 0 or b == 2:                print("+2(%d)"%b,end="")            elif b == 1:                print("+2", end="")            else:                print("+2(", end="")                two(b, 0)                print(")", end="")    else:        if b == 0 or b == 2:            print("2(%d)"%b,end="")        elif b == 1:            print("2", end="")        else:            print("2(", end="")            two(b, 0)            print(")", end="")x = eval(input())two(x, 0)deftwo(a,b):ifa!=1:two(a//2,b+1)ifa%2==1:ifb==0orb==2:print("+2(%d)"%b,end="")elifb==1:print("+2",end="")else:print("+2(",end="")two(b,0)print(")",end="")else:ifb==0orb==2:print("2(%d)"%b,end="")elifb==1:print("2",end="")else:print("2(",end="")two(b,0)print(")",end="")x=eval(input())two(x,0)deftwo(a,b):ifa!=1:two(a//2,b+1)ifa%2==1:ifb==0orb==2:print("+2(%d)"%b,end="")elifb==1:print("+2",end="")else:print("+2(",end="")two(b,0)print(")",end="")else:ifb==0orb==2:print("2(%d)"%b,end="")elifb==1:print("2",end="")else:print("2(",end="")two(b,0)print(")",end="")x=eval(input())two(x,0)deftwo(a,b):ifa!=1:two(a//2,b+1)ifa%2==1:ifb==0orb==2:print("+2(%d)"%b,end="")elifb==1:print("+2",end="")else:print("+2(",end="")two(b,0)print(")",end="")else:ifb==0orb==2:print("2(%d)"%b,end="")elifb==1:print("2",end="")else:print("2(",end="")two(b,0)print(")",end="")x=eval(input())two(x,0)