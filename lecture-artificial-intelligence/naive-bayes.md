# Example
```
Type           Long | Not Long || Sweet | Not Sweet || Yellow |Not Yellow|Total
             ___________________________________________________________________
Banana      |  400  |    100   || 350   |    150    ||  450   |  50      |  500
Orange      |    0  |    300   || 150   |    150    ||  300   |   0      |  300
Other Fruit |  100  |    100   || 150   |     50    ||   50   | 150      |  200
            ____________________________________________________________________
Total       |  500  |    500   || 650   |    350    ||  800   | 200      | 1000
             ___________________________________________________________________
```

# Prior
```
P(Banana)      = 0.5 (500/1000)
P(Orange)      = 0.3
P(Other Fruit) = 0.2
```

# Evidence
```
p(Long)   = 0.5
P(Sweet)  = 0.65
P(Yellow) = 0.8
```

# Likelihood
```
P(Long|Banana) = 0.8
P(Long|Orange) = 0  [Oranges are never long in all the fruit we have seen.]
 ....

P(Yellow|Other Fruit)     =  50/200 = 0.25
P(Not Yellow|Other Fruit) = 0.75
```

# Long Sweet Yellow
```
P(Banana|Long, Sweet and Yellow) 
      P(Long|Banana) * P(Sweet|Banana) * P(Yellow|Banana) * P(banana)
    = _______________________________________________________________
                      P(Long) * P(Sweet) * P(Yellow)

    = 0.8 * 0.7 * 0.9 * 0.5 / P(evidence)

    = 0.252 / P(evidence)


P(Orange|Long, Sweet and Yellow) = 0


P(Other Fruit|Long, Sweet and Yellow)
      P(Long|Other fruit) * P(Sweet|Other fruit) * P(Yellow|Other fruit) * P(Other Fruit)
    = ____________________________________________________________________________________
                                          P(evidence)

    = (100/200 * 150/200 * 50/200 * 200/1000) / P(evidence)

    = 0.01875 / P(evidence)
```