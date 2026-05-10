 suite of automated unit tests using the CUnit framework. The test suite is designed to handle edge cases, and ensure memory-safe execution.

Key Validation Areas:

Data Integrity & Input Validation: Ensures all user data (Names, Ages, Dates of Birth) adheres to expected formats and logical constraints, including handling complex date validations (like leap years and month lengths).

Logical Validation: Validates the logical relationship between different user attributes. For example, the system cross-references a user's age against their stated educational status to prevent impossible combinations.

Authentication & Security: Tests the robustness of the login mechanism, verifying successful logins, handling incorrect credentials gracefully, and explicitly preventing the creation of duplicate accounts.

System Capacity Constraints: Verifies the system's behavior and stability when it reaches maximum user capacity or encounters boundary-level stress conditions.
