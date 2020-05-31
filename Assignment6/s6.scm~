(define get-operator (lambda (op-symbol) 
  (cond 
    ((equal? op-symbol '+) +)
    ((equal? op-symbol '-) -)
    ((equal? op-symbol '*) *)
    ((equal? op-symbol '/) /)
    (else (error "s6-interpret: operator not implemented -->" op-symbol)))))

(define define-stmt? (lambda (e)
    ;; An expression is a define statement
    ;; if it is a list, and the first element
    ;; is define, the second element is a symbol,
    ;; and the third element is an expression.
    (and (list? e) (equal? (car e) 'define) (symbol? (cadr e)) (= (length e) 3))))

(define get-value (lambda (var env)
    (cond
      ;; If the environment is empty, then we could not find 
      ;; a binding in this environment.
      ((null? env) (error "s6-interpret: unbound variable -->" var))

      ;; Check if the first pair is a binding for the
      ;; variable that we are looking for, and if it is
      ;; return the current value of the variable.
      ((equal? (caar env) var) (cdar env))

      ;; Otherwise, search in the remaning of the environment.
      (else (get-value var (cdr env))))))

(define extend-env (lambda (var val old-env)
      ;; Add the new variable binding to the 
      ;; beginning of the old environment.
      (cons (cons var val) old-env)))

(define repl (lambda (env)
  (let* (
         ; first print out some prompt
         (dummy1 (display "cs305> "))

         ; READ an expression
         (expr (read))

         ; Form the new environment
         (new-env (if (define-stmt? expr)
                      (extend-env (cadr expr) (s6-interpret (caddr expr) env) env)
                      env))

         ; EVALuate the expression read
         (val (if (define-stmt? expr)
                  (cadr expr)
                  (s6-interpret expr env)))

         ; PRINT the value evaluated together
         ; with a prompt as MIT interpreter does
         (dummy2 (display "cs305: "))
         (dummy3 (display val))

         ; get ready for the next prompt
         (dummy4 (newline))
         (dummy4 (newline)))
     (repl new-env))))

(define s6-interpret (lambda (e env)
  (cond 
    ;; If the input expression is a number, then
    ;; the value of the expression is that number.
    ((number? e) e)

    ;; If the input expression is a symbol, then
    ;; get the current value binding of this variable.
    ((symbol? e) (get-value e env))

    ;; Otherwise, we must see a list.
    ((not (list? e)) 
          (error "s6-interpret: cannot evaluate -->" e))

    ;; First evaluate the value of the operands
    ;; and the procedure of the expression.
    (else 
       (let ((operands (map s6-interpret (cdr e) (make-list (length (cdr e)) env)))
             (operator (get-operator (car e))))

         ;; And finally apply the operator to the 
         ;; values of the operands
         (apply operator operands))))))

(define cs305-interpreter (lambda () (repl '())))
