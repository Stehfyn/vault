<!-- generated-from-dump2 -->
# miniMNIST-c — 200-Line MLP from Scratch

~200 lines of pure C — no BLAS, no CUDA, no TensorFlow — that trains a two-layer (input -> hidden -> softmax) MLP on MNIST to ~98% test accuracy in under 3 seconds per epoch on a laptop CPU. ReLU on the hidden layer, cross-entropy + softmax output, SGD with explicit forward/backward written out as nested loops. Builds with `-O3 -march=native -ffast-math`. Pedagogically the right size: small enough to read in one sitting, large enough to show every piece (mini-batches, weight init, backprop through softmax+CE, learning-rate schedule). Comparable in spirit to Andrej Karpathy's `nn.py`, but in C, which makes the matrix-multiply costs and the absence of automatic differentiation completely visible.

```c
// Conceptual training loop (real code is similarly direct):
for (int epoch = 0; epoch < EPOCHS; ++epoch) {
    shuffle(train_images, train_labels, n_train);
    for (int i = 0; i < n_train; i += BATCH) {
        // Forward: x -> h = relu(W1 x + b1) -> z = W2 h + b2 -> p = softmax(z)
        forward(W1, b1, W2, b2, x, h, z, p);
        // dz = p - onehot(y);  dW2 = dz h^T;  dh = (W2^T dz) * (h > 0);
        // dW1 = dh x^T;        update W1,b1,W2,b2 with lr * grads.
        backward_and_update(W1, b1, W2, b2, x, h, p, y, LR);
    }
    eval_accuracy(W1, b1, W2, b2, test_images, test_labels, n_test);
}
```

## References
- <https://github.com/konrad-gajdus/miniMNIST-c>
