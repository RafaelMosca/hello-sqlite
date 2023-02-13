A simple hello world sqlite extension.

### Building
`gcc -shared -fPIC -o hello.dll hello.c`

### Testing
`sqlite3 ":memory:" -cmd ".load hello" "SELECT HELLO('World') AS Greetings;"`

### Example output
```
$ sqlite3 ":memory:" -cmd ".load hello" "SELECT HELLO('World') AS Greetings;"
(0) Log: Hello World!
┌────────────────┐
│   Greetings    │
├────────────────┤
│ 'Hello World!' │
└────────────────┘
```
