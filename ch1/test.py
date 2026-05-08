import pexpect
import pytest

def run_test(input_data):
    # Spawn the process
    child = pexpect.spawn('./a.out', timeout=1)

    # Send raw data and EOF
    child.send(input_data)
    child.sendeof()

    # Wait for completion and capture output
    child.expect(pexpect.EOF)
    return child.before.decode().strip()

@pytest.mark.parametrize("payload, expected", [
    ("singleline", "0 1 10"),
    ("word1  word2\tword3", "0 3 18"),
    ("\n\n\n", "3 0 3"),
    ("  leading and trailing  ", "0 3 24"),
    ("", "0 0 0"),
])
def test_wc_core_logic(payload, expected):
    result = run_test(payload)
    assert result == expected

if __name__ == "__main__":
    pytest.main([__file__])