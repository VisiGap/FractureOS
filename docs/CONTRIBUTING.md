# Contributing to FractureOS

## Code Quality Standards

### Rust Code
- Follow Rust API guidelines
- Use `rustfmt` for formatting
- Run `clippy` and fix all warnings
- Write documentation for public APIs
- Add unit tests for new functionality

### C++ Code
- Follow C++20 best practices
- Use RAII for resource management
- Prefer `std::` containers over raw pointers
- Use `const` and `constexpr` where appropriate
- Follow the project's naming conventions

## Naming Conventions

### Rust
- Types: `PascalCase`
- Functions: `snake_case`
- Constants: `SCREAMING_SNAKE_CASE`
- Modules: `snake_case`

### C++
- Classes: `PascalCase`
- Functions: `snake_case`
- Variables: `snake_case`
- Constants: `kPascalCase`
- Namespaces: `snake_case`

## Commit Guidelines

- Use clear, descriptive commit messages
- Start with a verb in present tense
- Reference issue numbers when applicable
- Keep commits focused and atomic

Example:
```
Add page fault handler to kernel

Implements basic page fault handling with error reporting.
Fixes #123
```

## Pull Request Process

1. Fork the repository
2. Create a feature branch
3. Make your changes
4. Run tests and linters
5. Submit a pull request
6. Address review feedback

## Testing

- Write tests for new features
- Ensure all tests pass before submitting
- Test on QEMU before submitting

## Documentation

- Update relevant documentation
- Add inline comments for complex logic
- Update ARCHITECTURE.md for design changes
