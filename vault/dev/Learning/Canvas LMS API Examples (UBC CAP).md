<!-- generated-from-dump2 -->
# Canvas LMS API Examples (UBC CAP)

UBC CAP's worked examples for the Canvas LMS REST API + OAuth2, with notes on how LTI 1.3 (Learning Tools Interoperability) fits alongside it. Useful if you're building any tool that needs to read course rosters, post grades, or embed activities into Canvas - most of the official docs assume an institutional integration setup, this repo shows the "personal API token" simple path.

```python
# Conceptual API usage (paraphrased from the examples):
import requests
TOKEN = "<dev-token>"
HOST  = "https://canvas.ubc.ca"
def gget(path, **params):
    r = requests.get(f"{HOST}/api/v1/{path}",
                     headers={"Authorization": f"Bearer {TOKEN}"},
                     params=params)
    r.raise_for_status()
    return r.json()
courses = gget("courses")
for c in courses:
    students = gget(f"courses/{c['id']}/users", enrollment_type="student",
                    per_page=100)
```

## References
- <https://github.com/ubccapico/canvas_api_examples>
