<!-- generated-from-dump2 -->
# Twenty — Open-Source CRM in TypeScript

Twenty - open-source CRM (think Salesforce / HubSpot) built with TypeScript, NestJS on the backend, React + Recoil on the frontend. Worth a look as a reference of a substantial, modern TS monorepo: it uses Nx for build orchestration, a GraphQL + REST hybrid API, and is one of the cleanest examples of `class-validator` / `class-transformer` patterns plus a domain-driven entity layer (`Person`, `Company`, `Opportunity`, custom-field-extensible objects) on top of Postgres.

```text
# Self-host locally:
$ git clone https://github.com/twentyhq/twenty
$ cd twenty && yarn && yarn server:dev
# -> visit http://localhost:3001, sign up locally; data lands in Postgres.
```

## References
- <https://github.com/twentyhq/twenty>
