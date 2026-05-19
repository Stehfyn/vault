<!-- generated-from-dump2 -->
# FizzBuzz Enterprise Edition (satire)

Long-running satirical Java project where the trivial FizzBuzz problem is implemented with the full vocabulary of Enterprise Java pathology: AbstractFactoryFactory, StrategyFactory, multiple Maven modules, dependency-injected printers, configurable loop bounds via XML, and a 30-step UML diagram in the README. The point is not the code; it is a mirror held up to architecture-astronaut culture and a load-bearing reference any time someone says "we just need a couple of patterns here." If you ever find yourself sketching a similar diagram for real, this repo is the warning sign.

```java
// Representative of the style; actual class names live in the repo.
public class FizzBuzzApplicationContext {
    @Autowired private IntegerIntegerPrinter integerPrinter;
    @Autowired private FizzStrategyFactory fizzFactory;
    @Autowired private BuzzStrategyFactory buzzFactory;

    public void run(int upper) {
        for (int i = 1; i <= upper; i++) {
            new FizzBuzzStrategyContext(i, integerPrinter, fizzFactory, buzzFactory).evaluate();
        }
    }
}
```

## References
- <https://github.com/EnterpriseQualityCoding/FizzBuzzEnterpriseEdition>
