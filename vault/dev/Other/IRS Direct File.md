<!-- generated-from-dump2 -->
# IRS Direct File

The actual open-source code behind the IRS's free Direct File pilot — interview-based federal tax filing, English + Spanish, web + mobile. The interesting computer-science bit (and the reason this is worth a slow read for anyone modeling regulated domains) is the **Fact Graph**, a Scala-based knowledge graph that reasons about incomplete tax information: facts can be unknown, derived from other facts via tax-code rules, or directly entered by the user, and the engine knows what to ask next based on which downstream facts are still missing. Front end is React/TypeScript over a Java/Spring backend; Fact Graph is Scala. Politically interesting as a US federal codebase that actually shipped on GitHub.

```scala
// Conceptual shape of a Fact Graph definition (real syntax in
// direct-file/fact-dictionary/src/main/resources):
// Each "fact" declares its type, how to derive it, and what to ask the
// user when it cannot be derived.
//
// <Fact path="/totalIncome">
//   <Export>true</Export>
//   <Derived>
//     <Add>
//       <Dependency path="/wages"/>
//       <Dependency path="/interestIncome"/>
//       <Dependency path="/selfEmploymentIncome"/>
//     </Add>
//   </Derived>
// </Fact>
```

## References
- <https://github.com/IRS-Public/direct-file>
