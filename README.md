# clogs

## thread-safe c logging, put your clogs on

### usage
#### init clogs

```c
clogs_init(NULL); // no log file
```
or
```c
clogs_init("logfile.txt"); // all clog calls will be logged _and_ printed
```

#### add to clogs pool
```c
CLOG("info message");
CLOG_WARN("warn message");
CLOG_ERR("error message");
```

formatted mesasges are also supported, for example:
```c
CLOG("%d pairs of clogs", 2);
```

newlines are appended by clog and don't need to be passed.

#### print from clogs pool
```c
clogs_update()
```

`clogs_update()` should be called periodically to flush the clogs queue,
printing any messages. This should also handle OS signals, however this is
still in development (see issue #2)


#### free clogs
```c
clogs_close()
```

`clogs_close()` will close the clogs log file and destroy the internal mutexes.
Must be called to avoid memory leaks

### unsafe usage
```c
COUT("info message");
COUT_WARN("warn message");
COUT_ERR("error message");
```
The `COUT` macros take the same parameters as our `CLOG` macros, however they
are *not* thread-safe. These should *only* be used on the main thread.

As the name implies, they *do not log to a file*. However as a result, they can
be called when clog isn't initilised.
