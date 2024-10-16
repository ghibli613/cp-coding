# Generates cpp.json with snippets for VSCode

import os
import json
import sys

snippets = {}

for subdir in os.walk('.'):
  for filename in subdir[2]:
    name, extension = filename.split('.')
    if extension != 'h':
      continue

    if name in snippets:
      print(f'error: duplicate snippet {name}', file=sys.stderr)
      exit(0)

    path = subdir[0] + '/' + filename
    with open(path, 'r') as f:
      snippet = {
        "prefix": name,
        "body": [line.rstrip() for line in f.readlines()],
        "description": name
      }
      snippets[name] = snippet

    print(f'generated snippet {name}', file=sys.stderr)

with open('../.vscode/cp.code-snippets', 'w') as f:
  f.write(json.dumps(snippets, indent=4))

print('done', file=sys.stderr)
