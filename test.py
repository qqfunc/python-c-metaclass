"""Unit test for ThirdObject."""

from cmeta import ThirdObject


def test_thirdobject_value() -> None:
    """Test ThirdObject.value."""
    assert ThirdObject().value == 0


if __name__ == "__main__":
    test_thirdobject_value()
